#Gf24: mx = x^4 + x + 1 
#mx = 1 0 0 1 1 => x^4 = x + 1 => [0011]


#ham xor voi so nhi phan
def xor(x,y):
    kq = [0,0,0,0]
    for i in range (len(x)):
        if x[i] == y[i]:
            kq[i] = 0
        else:
            kq[i] = 1
    return kq

#ham nhan x voi gx
def mul_x_fx(tmp):
    tran = tmp[0]
    tmp = [tmp[1],tmp[2], tmp[3], 0] #khi x.fx thi fx dich trai 1
    if tran == 1: tmp = xor(tmp, [0,0,1,1]) #xor de cho b ve GF(2^4)
    return tmp

#ham nhan fx voi gx
#Cach1:
def mul_fx_gx_1(a,b):
    gx_1 = b
    x_gx = mul_x_fx(gx_1)
    x2_gx = mul_x_fx(x_gx)
    x3_gx = mul_x_fx(x2_gx)     
    
    re = [0,0,0,0]
    
    if a[0] == 1: re = xor(re, x3_gx) #trong da thuc fx co x^3
    if a[1] == 1: re = xor(re, x2_gx) 
    if a[2] == 1: re = xor(re, x_gx) 
    if a[3] == 1: re = xor(re, gx_1)
    
    return re
#Cach2:
def mul_fx_gx(a,b):
    tmp = b
    re = [0,0,0,0]
    for i in range(len(a)):
        if a[3-i] == 1: #quy uoc [0] la x^3
            re = xor(re, tmp)
        tmp = mul_x_fx(tmp)
        print("tmp = ", tmp)
    return re
    

a = list(map(int, input("Nhap he so cua f(x) (4 he so): ").split()))
b = list(map(int, input("Nhap he so cua g(x) (4 he so): ").split()))
re = mul_fx_gx(a,b)
print("Ket qua phep nhan f(x) va g(x): ", re)