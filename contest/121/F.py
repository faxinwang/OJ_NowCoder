T = int(input())
for kiss in range(1, T+1):
    x,n,k = list(map(int, input().split()))
    a = x**n
    ans , b = 0 , 1
    while b <= a:
        b *=  k
        ans += 1
    print("Case %d: %d"%(kiss, ans))