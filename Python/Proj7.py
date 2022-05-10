def gen_key(size, e):
  p = random_prime((2^size)-1, 2^(size-1))
  q = random_prime((2^size)-1,2^(size-1))
  n = p * q
  d = inverse_mod(e,(p-1)*(q-1))
  return n,e,d


def txt_to_num(msg_in):
    msg_idx = list(map(ord, msg_in))
    print(msg_idx)
    num = ZZ(msg_idx,256)
    print('this is after ZZ function: ', num)
    return num

def num_to_txt(num_in):
     msg_idx = list(num_in.digits(256))
     print('this is after num.digits: ', msg_idx)
     m = list(map(chr,msg_idx))
     print('this is m in num 2 txt: ', m)
     m = ''.join(m)
     return m

def encrypt(plain_txt,e,n):
    m = txt_to_num(plain_txt)
    print('Encrypt, this is n: ', n)
    print('Encrypt, this is e: ', e)
    c = power_mod(m, e ,n)
    print('Encrypt, this is m: ', m)
    return c


def decrypt(c,d,n):
  m = power_mod(c,d,n)
  print('Decrypt, This is m : ', m)
  plain_txt = num_to_txt(m)
  print('Decrypt, after num to text: ', plain_txt)
  return plain_txt


def main():
   size = input('Enter in values for size ')
   size = int(size)
   e = input('Enter in values for e ')
   e = int(e)
   plain_txt = input('Enter in a sentence ')
   n, e, d = gen_key(size, e)
   c = encrypt(plain_txt,e,n)
   p = decrypt(c,d,n)



