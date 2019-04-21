using System;
using System.Collections.Generic;
using System.IO;

namespace EightWeek
{
    class Program
    {
        private static StreamWriter _out;

        private static void Main(string[] args) 
        {
            _out = new StreamWriter("output.txt");
            Console.SetOut(_out);
            new SetRunner().Run(File.ReadAllLines("input.txt"));
            DisposeIO();
        }

        private static void DisposeIO() 
        {
            _out?.Dispose();
        }

    }

    public class SetRunner
    {
        private Set _set;
        private Dictionary<char, Action<long>> instructions;

        public SetRunner()
        {
            _set = new Set();
            this.InitializeCommands();
        }

        public void InitializeCommands()
        {
            instructions = new Dictionary<char, Action<long>>
            {
                ['A'] = (number) => { _set.Add(number); },
                ['D'] = (number) => { _set.Delete(number); },
                ['?'] = (number) => { Console.WriteLine(_set.Find(number) ? 'Y' : 'N'); }
            };
        }
        public void Run(string[] commands)
        {
            for (int i = 1; i < commands.Length; i++)
            {
                var args = commands[i].Split();
                var number = long.Parse(args[1]);
                instructions[args[0][0]](number);
            }
        }
    }

    public class Set
    {
        private LinkedList<long>[] _array;
        private int _divider;

        public Set(int primeNumber = 65537)
        {
            _divider = primeNumber;
            _array = new LinkedList<long>[_divider * 2 - 1];
        }

        private long Hash(long number)
        {
            return number % _divider + 65536;
        }

        private bool isListExists(long number)
        {
            return _array[Hash(number)] == null ? false : true;
        }

        public void Add(long number)
        {
            if (!isListExists(number))
            {
                _array[Hash(number)] = new LinkedList<long>();
                _array[Hash(number)].AddFirst(number);
            } 
            else 
            {
                if (!Find(number,true))
                {
                    _array[Hash(number)].AddFirst(number);
                }
            }
           
        }

        public bool Find(long number, bool isListChecked = false)
        {
            if (isListChecked || isListExists(number))
            {
                return _array[Hash(number)].Find(number) == null ? false : true;
            }
            return false;
        }

        public void Delete(long number)
        {
            if (Find(number))
            {
                _array[Hash(number)].Remove(number);
            }
        }
    }
}
