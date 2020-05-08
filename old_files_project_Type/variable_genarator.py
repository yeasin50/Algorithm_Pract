#on May 23, 2019 for bubbul Ahmed(chlng)
import random

total = 100000

file = open("chlng.txt","w+")
file.write(r'''
#include<stdio.h> 
#include<ctype.h>
int main()
{
// variable declaration
    char ch[6];
    int sum = 0;
    printf("Wanna scan variables? Press y \n   else assigned value will be calculated");
    gets(ch);
    
''')

for i in range(total):
    file.write("""int var%d = """%(i+1))
    r = random.randint(1, 100)
    file.write("""%d ;\n""" %(r))


file.write(r"""
if(toupper(ch[0])=='Y'){""")

for i in range(total):
    file.write(""" scanf("%d",""")
    file.write(""" &var%d) ;\n""" %(i+1))

file.write("}\n\n")

file.write("""sum = var1 """)
for i in range(1, total):
    if( i%10==0 ):
        file.write("\ \n")
    file.write("""+ var%d""" %(i+1))

file.write(";\n\n")

file.write(r""" 
    printf("sum = %d\n",sum);
    
    return 0;
    }
""")
