import subprocess

# search
"""
	linsearchseq
	linsearchpar
"""
# sort
"""
	inssortseq
	inssortpar
"""

subprocess.check_call(
	["gcc", "-o", "linsearchseq", "linsearchseq.c"]
);
print("COMPILED :: IN: linsearchseq.c :: OUT: linsearchseq");

subprocess.check_call(
["gcc", "-fopenmp", "linsearchpar.c", "-o", "linsearchpar"]
);
print("COMPILED :: IN: linsearchpar.c :: OUT: linsearchpar");

subprocess.check_call(
["gcc", "-fopenmp", "inssortseq.c", "-o", "inssortseq"]
);
print("COMPILED :: IN: inssortseq.c :: OUT: inssortseq");

subprocess.check_call(
["gcc", "-fopenmp", "inssortpar.c", "-o", "inssortpar"]
);
print("COMPILED :: IN: inssortpar.c :: OUT: inssortpar");
