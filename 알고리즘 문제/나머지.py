A,B,C = input().split(' ')
A = int(A)
B = int(B)
C = int(C)
result1 = (A+B)%C
result2 = ((A%C) + (B%C))%C
result3 = (A*B)%C
result4 = ((A%C) * (B%C))%C
print(result1)
print(result2)
print(result3)
print(result4)

#처음에는 ABC를 따로 받았는데 그것 때문에 런파일 에러가 발생했었다. 한번에 받으니까 문제 해결됨
