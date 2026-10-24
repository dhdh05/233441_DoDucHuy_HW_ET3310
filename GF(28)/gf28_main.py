#ham nhan fx voi gx
def mul_fx_gx(a,b):
    #khoi tao mang c chua ket qua phep nhan f(x) va g(x)
    c = [0] * 15 #c = len(a) + len(b) - 1 = 8 + 8 - 1 = 15
    for i in range(len(a)):
        if a[i] == 1: #a[i] la he so cua f(x) tai bac 7-i
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
# gf(2^8) voi m(x) = x^8+x^4+x^3+ x+ 1
def mod_c(c):
    m = [1,0,0,0, 1, 1, 0, 1, 1] #m[0] tuong ung voi x^8
    thuong = [0] * 7 #bac cao nhat cua thuong la x^14/x^8 = x^6
    
    #xet 7 gia tri dau (do day luu tru bac cao hon mx)
    for i in range(7):
        if c[i] == 1:
            thuong[i] = 1 #x^(14-i)/x^8 = x^(6-i)
            
            #nhan m(x) voi x^(6-i)
            mul = [0] * 15
            for j in range(9): #duyet cac he so cua m(x)
                mul[i+j] = m[j] #nhan m(x) voi x^(6-i)
            #rut gon sau chia
            for k in range(15):
                if c[k] == mul[k]:
                    c[k] = 0
                else:
                    c[k] = 1
    du = [c[7], c[8], c[9], c[10], c[11], c[12], c[13], c[14]] #day la c sau khi mod
    return thuong, du

a = list(map(int, input("Nhap he so cua f(x) (8 he so): ").split()))
b = list(map(int, input("Nhap he so cua g(x) (8 he so): ").split()))
c = mul_fx_gx(a,b)
print("Ket qua phep nhan f(x) va g(x): ", c)
print("Ket qua phep chia c(x) cho m(x): ")
thuong, du = mod_c(c)
print("Du (c sau mod): ", du)
