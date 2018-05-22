from queue import *
def isBip(b,n):
	color = [-1]*(n+2)
	color[1] = 1
	q = Queue(maxsize=0)
	q.put_nowait(1)
	while q.empty()==False:
		u = q.get()
		for v in range(1,n+1):
			if b[u][v] and color[v]==-1:
				color[v]=1-color[u]
				q.put_nowait(v)
			elif b[u][v] and color[v]==color[u]:
				return False
	return True
t = int(input())
j=1
while j<=t:
	n = [0]*2
	a = [0]*(1001)
	b = [[True for i in range(0,1001)] for k in range(0,1001)]
	n = [int(z) for z in input().split()]
	for i in range(1,n[0]+1):
		b[i][i]=False
	for i in range(0,n[1]):
		a = [int(k) for k in input().split()]
		b[a[0]][a[1]] = False
		b[a[1]][a[0]] = False
	if isBip(b,n[0]):
		print("Yes")
	else:
		print("No")
	j+=1
