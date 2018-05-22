t = int(input())
j = 1
while j<=t:
	s = input()
	l = 0
	r = len(s)-1
	f=0
	while l<r:
		if s[l]!='.' and s[r]!='.':
			if s[l]!=s[r]:
				f=1
				break
		else:
			if s[l]=='.' and s[r]!='.':
				a = list(s)
				a[l]=a[r]
				s = ''.join(a)
			elif s[l]!='.' and s[r]=='.':
				a = list(s)
				a[r] = a[l]
				s = ''.join(a)
			else:
				a=list(s)
				a[r]=a[l]='a'
				s = ''.join(a)
		l+=1
		r-=1
	if len(s)%2!=0:
		if s[l]=='.':
			a=list(s)
			a[l]='a'
			s = ''.join(a)
	if f==1:
		print(-1)
	else:
		print(s)
	j+=1


		


