# python Calculator.py 
# ‘5 * 7’

x = input().replace("'","")

a = 0
b = 0

if '+' in x:
  a = x.split('+')
  b = int(a[0]) + int(a[1])
elif '-' in x:
  a = x.split('-')
  b = int(a[0]) - int(a[1])
elif '/' in x:
  a = x.split('/')
  b = int(a[0]) // int(a[1])
elif '*' in x:
  a = x.split('*')
  b = int(a[0]) * int(a[1])

print(x + " = " + str(b))


  