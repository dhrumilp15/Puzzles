FLAG = "ffadccb05b5892418ff068dd9d42231e8caf8ebb289ea1873f0a474cabe7ce598db77bac9dfef1d7c2b5af3c35bf5844c082"
encd = "bajbgfapbcclgoejgpakmdilalpomfdlkngkhaljlcpkjgndlgmpdgmnmepfikanepopbapfkdgleilhkfgilgabldofbcaedgfe"
s = []
for let in range(len(FLAG)):
    s.append(chr(ord(FLAG[let]) ^ ord(encd[let])))
print(''.join(s))