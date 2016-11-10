import sys

input = sys.argv[1]
print input
input = int(input)
strs = []
if input < 0:
    strs.append('-')
    input = -input

while (input > 0 ):
    print input
    left = input%10
    strs.append(str(left))
    input = input/10

print strs
output = int(''.join(strs))
print outpt
