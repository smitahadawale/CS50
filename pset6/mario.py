import cs50

print('Height: ', end='');
h = int(input());


while(h<0 or h > 23):
   print('Height: ', end='');
   h = cs50.get_int()
   if h >= 0 and h <= 23:
            break
        

for i in range(h):
        for j in range(h - i-1):
            print(" ", end = "")
        for k in range(i+2):
            print("#", end = "")
        print("")