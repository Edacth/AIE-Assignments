using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media.Imaging;

namespace MySteamQuery
{

    public class GameListRootobject
    {
        public GameListResponse response { get; set; }
    }

    public class GameListResponse
    {
        public int game_count { get; set; }
        public Game[] games { get; set; }
    }

    public class Game
    {
        public int appid { get; set; }
        public string name { get; set; }
        public int playtime_forever { get; set; }
        public string img_icon_url { get; set; }
        public BitmapImage img { get; set; }
        public string img_logo_url { get; set; }
        public bool has_community_visible_stats { get; set; }

        public void GenImg()
        {

            img.BeginInit();
            img.UriSource = new Uri(img_icon_url, UriKind.Absolute);
            img.EndInit();
        }
    }

}
