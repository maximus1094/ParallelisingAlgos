import subprocess

subprocess.check_call(
	["gcc", "-o", "lin_search_norm", "lin_search_norm.c"]
);
print("COMPILED :: IN: lin_search_norm.c :: OUT: lin_search_norm");

subprocess.check_call(
["gcc", "-fopenmp", "lin_search_par.c", "-o", "lin_search_par"]
);
print("COMPILED :: IN: lin_search_par.c :: OUT: lin_search_par");
