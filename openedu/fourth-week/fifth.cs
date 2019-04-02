using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace tmp 
{
    public class Program 
    {
        private static StreamWriter _out;

        private static void Main(string[] args) 
        {
      
            _out = new StreamWriter("output.txt");
            Console.SetOut(_out);
            new Quack().Run(File.ReadAllLines("input.txt"));
            DisposeIO();
        }

        private static void DisposeIO() 
        {
            _out?.Dispose();
        }
    }

    public class Quack 
    {
        private readonly Queue<ushort> _queue = new Queue<ushort>();

        private Dictionary<int, ushort> _registers;

        private int _cursor;

        private Dictionary<char, Action<string>> _instructions;
        private Dictionary<string, int> _labels;
        private bool _isRunning;

        public void Run(string[] lines) 
        {
            _queue.Clear();
           
            _isRunning = true;
            DefineRegisters();
            DefineLabels(lines);
            DefineInstructions();

            while (_cursor < lines.Length && _isRunning) {
                Interpret(lines[_cursor]);
                _cursor++;
            }
        }

        private void Interpret(string s) 
        {
            if (char.IsDigit(s[0])) {
                Put(ushort.Parse(s));
                return;
            }

            _instructions[s[0]](s);
        }

        private void Print(int number)
        {
            Console.WriteLine(number);
        }
        private void Print(char c)
        {
            Console.Write(c);
        }
        private void changeCursor(string line, int indent)
        {
            string label = new string(line.Skip(indent).ToArray());
            _cursor = _labels[label];
        }
        private ushort Get() 
        {
            return _queue.Dequeue();
        }

        private void Put(int value) 
        {
            _queue.Enqueue((ushort) (value % Int16.MaxValue));
        }
        private void DefineLabels(string[] lines) 
        {
            _labels = lines
                .Select((s, i) => (label: s, line: i))
                .Where(s => s.label[0] == ':')
                .ToDictionary(tuple => new string(tuple.label.Skip(1).ToArray()), tuple => tuple.line);
        }
        private void DefineRegisters()
        {
            _registers = Enumerable.Range('a', 26)
                .ToDictionary(x => x, y => (ushort) 0);
        }
        private void DefineInstructions() 
        {
            _instructions = new Dictionary<char, Action<string>> 
            {
                ['+'] = s => { Put(Get() + Get()); },
                ['-'] = s => { Put(Get() - Get()); },
                ['*'] = s => { Put(Get() * Get()); },
                ['/'] = s => {
                    var a = Get();
                    var b = Get();
                    Put(b == 0 ? 0 : a / b);
                },
                ['%'] = s => {
                    var a = Get();
                    var b = Get();
                    Put(b == 0 ? 0 : a % b);
                },
                ['>'] = s => { _registers[s[1]] = Get(); },
                ['<'] = s => { Put(_registers[s[1]]); },
                ['P'] = s => { Print(s.Length == 1 ? Get() : _registers[s[1]]); },
                ['C'] = s => { Print((char) ((s.Length == 1 ? Get() : _registers[s[1]]) % 256)); },
                [':'] = s => { },
                ['J'] = s => { changeCursor(s,1); },
                ['Z'] = s => {
                    if (_registers[s[1]] == 0) {
                        changeCursor(s,2);
                    }
                },
                ['E'] = s => {
                    if (_registers[s[1]] == _registers[s[2]]) {
                        changeCursor(s,3);
                    }
                },
                ['G'] = s => {
                    if (_registers[s[1]] > _registers[s[2]]) {
                        changeCursor(s,3);
                    }
                },
                ['Q'] = s => { _isRunning = false; }
            };

            
        }
    }
}
