input_path = 'input.txt'
output_path = 'output.txt'
f = open(input_path, 'r')
a_str,b_str = f.read().split(' ')
f.close()

a = int(a_str)
b = int(b_str)

f = open(output_path,'w')
f.write(str(a+b*b))
f.close()