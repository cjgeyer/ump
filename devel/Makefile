algo.pdf : algo.tex
	pdflatex algo.tex
algo.tex : algo.Rnw
	Rscript -e 'knitr::knit("algo.Rnw")'
