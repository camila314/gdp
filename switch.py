a = open("t.txt", "r").readlines()
def sign_extend_32_64(x):
    bits = 32
    m = 1 << (bits - 1)
    return (x ^ m) - m

base = int(input("base addr:"), 16)
offset = int(input("offset:"))
def mapit(line, lnum):
	data = sign_extend_32_64(int(line[2:], 16)) + base
	newline = f"case {lnum+offset}:\n    goto loc_1000" + hex(data)[2:] + ";\n    break;\n"
	return newline
	"""if line.startswith("    "):
		newline = "    goto loc_100"
		newline += str(hex(sign_extend_32_64(int(line.replace("    0x","0"), 16)) + 0x7a638)[2:]) + ";\n"
		return newline
	else:
		return line"""

out = ""
for i in range(len(a)):
	out += mapit(a[i], i)
print(out)