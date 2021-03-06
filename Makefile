TARGET=CS444_final_paper
HTML=main_html
SRC=execeg.c
WINPROC=wincreateproc.c
MEMLX=mmapeg.c
MEMWIN=winmemeg.c
default: pdf

both: pdf html

pdf: ${TARGET}.tex 
#	pygmentize the input source file -- THIS NAME SHOULD BE SAFE
	pygmentize -f latex -o __${SRC}.tex ${SRC}
	pygmentize -f latex -o __${WINPROC}.tex ${WINPROC}
	pygmentize -f latex -o __${MEMLX}.tex ${MEMLX}
	pygmentize -f latex -o __${MEMWIN}.tex ${MEMWIN}
#	run latex twice to get references correct
	pdflatex ${TARGET}.tex
#	you can also have a bibtex line here
	bibtex $(TARGET)
	pdflatex $(TARGET).tex
	pdflatex $(TARGET).tex
#	remove the pygmentized output to avoid cluttering up the directory
	rm __${SRC}.tex
	rm __${WINPROC}.tex

#ps: dvi
#	dvips -R -Poutline -t letter ${TARGET}.dvi -o ${TARGET}.ps

#pdf: ps
#	ps2pdf ${TARGET}.ps


html:
	cp ${TARGET}.tex ${HTML}.tex
	latex ${HTML}.tex
	latex2html -split 0 -noshow_section_numbers -local_icons -no_navigation -noinfo -noaddress ${HTML}

	sed 's/<BR><HR>//g' < ${HTML}/index.html > ${HTML}/index2.html
	mv ${HTML}/index2.html ${TARGET}.html
	rm ${HTML}.*
	rm -rf ${HTML}

clean:
	rm -f $(TARGET).{pdf,aux,log,out,toc,dvi,ps,blg,bgg,bbl}
