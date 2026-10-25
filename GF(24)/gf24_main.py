#ham nhan fx voi gx
def mul_fx_gx(a,b):
    #khoi tao mang c chua ket qua phep nhan f(x) va g(x)
    c = [0,0,0,0,0,0,0] #c = len(a) + len(b) - 1 = 4 + 4 - 1 = 7
    for i in range(len(a)):
        if a[i] == 1:
            for j in range(len(b)):
                if b[j] == 1:
                    c[i+j] += 1
                    print("c[",i+j,"] = ", c[i+j])
    # mod 2 he so c ve GF(2)
    for i in range(len(c)):
        c[i] = c[i] % 2
    print(c)
    return c 

# lay mod c(x) voi da thuc toi gian m(x)
# gf(2^4) voi m(x) = x^4 + x + 1
def mod_c(c):
    m = [1, 0, 0, 1, 1] #m[0] tuong ung voi x^4
    thuong = [0, 0, 0] #bac cao nhat cua thuong x^6/x^4 = x^2
    
    for i in range(3):
        if c[i] == 1:
            thuong[i] = 1 #x^(6-i)/x^4 = x^(2-i)
            
             
            mul = [0,0,0,0,0,0,0]
            for j in range(5): #duyet cac he so cua m(x)
                mul[i+j] = m[j] #nhan m(x) voi x^(2-i)
            
            #rut gon sau chia
            for k in range(7):
                if c[k] == mul[k]:
                    c[k] = 0
                else:
                    c[k] = 1
    du = [c[3], c[4], c[5], c[6]] #day la c sau khi mod
    return thuong, du

a = list(map(int, input("Nhap he so cua f(x) (4 he so): ").split()))
b = list(map(int, input("Nhap he so cua g(x) (4 he so): ").split()))
c = mul_fx_gx(a,b)
print("Ket qua phep nhan f(x) va g(x): ", c)
print("Ket qua phep chia c(x) cho m(x): ")
thuong, du = mod_c(c)
print("Du (c sau mod): ", du)
