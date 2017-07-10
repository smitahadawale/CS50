import cs50
import sys

def main():
    if len(sys.argv) != 2:
        print("Key is Missing")
        exit(1)

    print("Plaintext:",end="")
    key = int(sys.argv[1])
    ciphertext = []
    message = cs50.get_string()
    print("Ciphertext:",end="")
    for symbol in message:
        if symbol.isalpha():
            ciphertext.append(caesar(symbol, key))
        else:
             ciphertext.append(symbol)
                
    print("".join( ciphertext))
    exit(0)

def caesar(char, key):
    if char.isupper():
        return chr(((ord(char) - 65 + key) % 26) + 65)
    elif char.islower():
        return chr(((ord(char) - 97 + key) % 26) + 97)
    else:
        return chr(char)
        
if __name__ == "__main__":
    main()