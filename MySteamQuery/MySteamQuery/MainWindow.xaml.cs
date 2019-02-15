using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Net;
using Newtonsoft;
using System.IO;
using MySteamQuery;

namespace MySteamQuery
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {

            string webApiKey = File.ReadAllText(@"secretKey.txt");
            string userID = "76561198118706000";

            InitializeComponent();

            ProfileRootobject PRO = ProfileDataRequest(webApiKey, userID);
            GameListRootobject GLRO = GameListRequest(webApiKey, userID);
            foreach (var Game in GLRO.response.games)
            {
                Game.GenImg();
            }

            txtbox_1.Text = PRO.response.players[0].personaname;

            BitmapImage avatar = new BitmapImage();
            avatar.BeginInit();
            avatar.UriSource = new Uri(PRO.response.players[0].avatarfull, UriKind.Absolute);
            avatar.EndInit();

            img_1.Source = avatar;

            list1.DataContext = GLRO.response.games;
            return;
        }

        public ProfileRootobject ProfileDataRequest(string ApiKey, string userID)
        {
            string gProfileData = "http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key=[webapikey]&steamids=[userid]";

            string url = gProfileData;
            url = url.Replace("[webapikey]", ApiKey); //replace the webapikey
            url = url.Replace("[userid]", userID);

            WebRequest request = WebRequest.Create(url);
            WebResponse response = request.GetResponse();
            Stream dataStream = response.GetResponseStream();
            StreamReader reader = new StreamReader(dataStream);
            string responseFromServer = reader.ReadToEnd();
            reader.Close();
            response.Close();
            Console.WriteLine(responseFromServer);

            return Newtonsoft.Json.JsonConvert.DeserializeObject<ProfileRootobject>(responseFromServer);

        }

        public GameListRootobject GameListRequest(string ApiKey, string userID)
        {
            string gOwnedGames = "http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key=[webapikey]&steamid=[userid]&format=json&include_appinfo=1";

            string url = gOwnedGames;
            url = url.Replace("[webapikey]", ApiKey); //replace the webapikey
            url = url.Replace("[userid]", userID);

            WebRequest request = WebRequest.Create(url);
            WebResponse response = request.GetResponse();
            Stream dataStream = response.GetResponseStream();
            StreamReader reader = new StreamReader(dataStream);
            string responseFromServer = reader.ReadToEnd();
            reader.Close();
            response.Close();
            Console.WriteLine(responseFromServer);

            return Newtonsoft.Json.JsonConvert.DeserializeObject<GameListRootobject>(responseFromServer);

        }
    }
}
