t = int(input())
j = 1
while j<=t:
	count1=count2=0
	a = input()
	for i in range(0,len(a)):
		if a[i]=='0':
			count1+=1
		else:
			count2+=1
	if count1==1 or count2==1:
		print("Yes")
	else:
		print("No")
	j+=1
