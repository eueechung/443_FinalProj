
all: flow.png distance.png bij1.png bij2.png qap1.png qap2.png main.tex
	pdflatex main.tex

flow.png:
	circo -Tpng flow.dot > flow.png

distance.png:
	circo -Tpng distance.dot > distance.png

bij1.png:
	dot -Tpng bij1.dot > bij1.png

bij2.png:
	dot -Tpng bij2.dot > bij2.png

qap1.png:
	circo -Tpng qap1.dot > distance.png

qap2.png:
	circo -Tpng qap2.dot > distance.png

