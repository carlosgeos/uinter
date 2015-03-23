TEXFILE = main
CPPFILE = Uinter

$(TEXFILE).pdf: $(TEXFILE).tex
	latexmk -xelatex -output-directory=tex_files $(TEXFILE)

compile: $(CPPFILE).cpp
	./cpp $(CPPFILE).cpp

view: $(TEXFILE).pdf
	evince tex_files/$(TEXFILE).pdf &

clean:
	rm -rfv tex_files
