import random


def getPI(n):
    total_point =0
    total_point_in_Area = 0
        
    for _ in range(n):
        
        x = random.uniform(0,1)
        y = random.uniform(0,1)
        
        print('X = ',x,"Y  = ",y)

        point_poss = x**2 + y**2

        if point_poss <=1:
            total_point_in_Area +=1
        total_point +=1

    print("\n\nDots In Circle= ", total_point_in_Area, "\nTotal Dot= ",total_point)
    return (4*total_point_in_Area) /total_point


n =int(input("Enter the amount of Point >> "))
print("Got Pi = ", getPI(n))
