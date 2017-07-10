import cs50

count=0;
quarter=25
dim=10
nickel=5
penny=1
print('O hai! How much change is owed?')
change=cs50.get_float()
amount=change*100
while amount<0:
             print("How much change is owed?\n")
             change=cs50.get_float(); 
            
while amount>=quarter:
    amount=amount-quarter
    count=count+1
    
while amount>=dim:
    amount=amount-dim
    count=count+1
    
while amount>=nickel:
    amount=amount-nickel
    count=count+1
    
while amount>=penny or amount>0:
    amount=amount-penny
    count=count+1
    
print(count)

    