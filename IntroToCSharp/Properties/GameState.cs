using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Properties
{
    public enum gameStates
    {
        Warmup,
        InProgress,
        PostMatch
    }
    class GameState
    {
        gameStates currentState = 0;
        public gameStates CurrentState
        {
            get
            {
                return currentState;
            }
            set
            {
                gameStates oldState = currentState;
                currentState = value;
                OnStateChanged(oldState);
            }
        }

        void OnStateChanged(gameStates oldState)
        {
            Console.WriteLine("Do stuff to transition from " + oldState.ToString() + " to " + currentState.ToString());
        }
    }
}
