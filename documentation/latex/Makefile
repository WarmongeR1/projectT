all: clean projectT-documentation.pdf

pdf: projectT-documentation.pdf

projectT-documentation.pdf: output/projectT-documentation.tex
	pdflatex output/projectT-documentation.tex
	makeindex output/projectT-documentation.idx
	pdflatex output/projectT-documentation.tex
	latex_count=5 ; \
	while egrep -s 'Rerun (LaTeX|to get cross-references right)' output/projectT-documentation.log && [ $$latex_count -gt 0 ] ;\
	    do \
	      echo "Rerunning latex...." ;\
	      pdflatex output/projectT-documentation.tex ;\
	      latex_count=`expr $$latex_count - 1` ;\
	    done


clean:
	rm -f *.ps *.dvi *.aux *.toc *.idx *.ind *.ilg *.log *.out output/projectT-documentation.pdf
