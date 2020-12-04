def rev(var):
    for line in reversed(list(open(var))):
        print(line.rstrip())
var=input("enter the file name from directory")
rev(var)
    
   
        
    
