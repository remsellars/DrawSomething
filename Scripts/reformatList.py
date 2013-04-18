# m_Word[i] = "word"; 
import sys
length = sys.argv[1]
Infile = open("DrawSomething" + str(length) +"Characters.txt", 'rt')
Outfile = open(str(length) +"charforvector.txt", 'wt')
imax = len(Infile.readlines())
index = 0
Infile.seek(0)

while index<imax:
	in_line = Infile.readline()
	Outfile.write("m_Word[" + str(index) + "]" + "=\""+ in_line[0:int(length)] + "\";\n")
	print ("m_Word[" + str(index) + "]" + "=\""+ in_line[0:int(length)] + "\";\n")
	
	index = index+1	

Infile.close()
Outfile.close()

	

