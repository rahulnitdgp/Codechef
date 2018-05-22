t = int(input())
j=1
while j<=t:
	maxx=0
	n = int(input())
	ans = [0]*n
	for i in range(0,n):
		c =	[int(z) for z in input().split()]
		arr = [0]*6
		count=0
		for m in range(1,len(c)):
			r=c[m]-1
			if arr[r]==0:
				count+=1
			arr[r]+=1
		#print(arr)
		arr.sort()
		#print(arr)
		#print(count)
		if count==4:
			ans[i]=c[0]+arr[2]
			#print(ans[i])
		elif count==5:
			ans[i]=c[0]+ arr[1] + arr[2] 
			#print(ans[i])
		elif count==6:
			ans[i]=c[0] + 2*arr[0] + arr[1] + arr[2]
		else:
			ans[i]=c[0]
		if ans[i]>maxx:
			maxx=ans[i]
	count=0
	for i in range(0,n):
		if ans[i] == maxx:
			count+=1
			k=i
	if count>1:
		print("tie")
	else:
		if k==0:
			print("chef")
		else:
			print(k+1)
	j+=1

