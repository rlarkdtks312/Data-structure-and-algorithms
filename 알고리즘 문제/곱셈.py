A,B,C = input().split(' ')
A = int(A)
B = int(B)
C = int(C)

def pow(a, n):
    if n == 1:
        return a % C
    else:
        num = pow(a, n // 2)
        if n % 2 == 0:
            return num*num % C
        else:
            return num*num*a % C
print(pow(A, B))



'''
A,B,C = input().split(' ')
A = int(A)
B = int(B)
C = int(C)

def pow(a, n):
    if n==0:
        return a
    if n == 1:
        a = a*a
        return a
    if (n%2) != 0:
        a=a**2 
        n = (n // 2) + 1
        return pow(a, n)
    else:
        a = a**2
        n = n//2
        return pow(a, n)

print(pow(A, B) % C)
'''
