def gen_key(size, e):
  #Generate two random prime numbers (p & q)
  p = random_prime((2^size)-1, 2^(size-1))
  q = random_prime((2^size)-1,2^(size-1))
  #Calculate n as the product of p & q
  n = p * q
  #Calculate the modular inverse of e, d
  d = inverse_mod(e,(p-1)*(q-1))
  #Return the values of n, e, & d
  return n,e,d


def txt_to_num(msg_in):
    #Convert the message to a list of ASCII values
    msg_idx = list(map(ord, msg_in))
    print(msg_idx)
    #Convert the list of ASCII values to a single integer
    num = ZZ(msg_idx,256)
    print('this is after ZZ function: ', num)
    #Return the integer representation of the message
    return num

def num_to_txt(num_in):
     #Convert the integer to a list of ASCII values
     msg_idx = list(num_in.digits(256))
     print('this is after num.digits: ', msg_idx)
     #Convert the list of ASCII values to a string
     m = list(map(chr,msg_idx))
     print('this is m in num 2 txt: ', m)
     m = ''.join(m)
     #Return the string representation of the message
     return m

def encrypt(plain_txt,e,n):
    #Convert the plain text message to an integer
    m = txt_to_num(plain_txt)
    print('Encrypt, this is n: ', n)
    print('Encrypt, this is e: ', e)
    #Encrypt the message using the public key (e,n)
    c = power_mod(m, e ,n)
    print('Encrypt, this is m: ', m)
    #Return the encrypted message
    return c


def decrypt(c,d,n):
  #Decrypt the encrypted message using the private key (d,n)
  m = power_mod(c,d,n)
  print('Decrypt, This is m : ', m)
  #Convert the decrypted message from an integer to a string
  plain_txt = num_to_txt(m)
  print('Decrypt, after num to text: ', plain_txt)
  #Return the decrypted message
  return plain_txt


def main():
   #Get the size of the key to be generated
   size = input('Enter in values for size ')
   size = int(size)
   #Get the value of e to be used in the encryption
   e = input('Enter in values for e ')
   e = int(e)
   #Get the plain text message to be encrypted
   plain_txt = input('Enter in a sentence ')
   #To generate the key pair (n, e, d)
   n, e, d = gen_key(size, e)
   #Encrypt the message
   c = encrypt(plain_txt,e,n)
   #Decrypt the message
   p = decrypt(c,d,n)



