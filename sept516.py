is_prime = [1]*(1000010)
lpd = [1]*(1000010)
is_prime[0]=is_prime[1]=0
def sieve():
	for i in range(1,1000001):
		if is_prime[i]==1:
			k = i*i
			while k<=1000000:
				if is_prime[k]==1:
					is_prime[k]=0
				k+=i

def lpdd():
	for i in range(2,1000001):
		if i%2==0:
			lpd[i]=2
		elif i%3==0:
			lpd[i]=3
		elif i%5==0:
			lpd[i]=5
		else:
			j=7
			while (j*j)<=i:
				if i%j==0:
					lpd[i]=j
					break
				elif i%(j+4)==0:
					lpd[i]=j+4
					break
				elif i%(j+6)==0:
					lpd[i]=j+6
					break
				elif i%(j+10)==0:
					lpd[i]=j+10
					break
				elif i%(j+12)==0:
					lpd[i]=j+12
					break
				elif i%(j+16)==0:
					lpd[i]=j+16
					break
				elif i%(j+22)==0:
					lpd[i]=j+22
					break
				elif i%(j+24)==0:
					lpd[i]=j+24
					break
				j+=30
			if j*j > i:
				lpd[i] = i

sieve()
lpdd()
while j<=t:
	z = 0
	n = [int(x) for x in input().split()]
	#m = int(input())
	result = [0]*(n[1])
	a = [int(x) for x in input().split()]
	for i in range(0,n[1]):
		b = [int(y) for y in input().split()]
		if b[0]==0:
			update(b[1],b[2],a)
		else:
			result[z] = get(b[1],b[2],a)
			#print(result[z])
			z+=1
	result = result[0:z]
	print(*result)
	j+=1

