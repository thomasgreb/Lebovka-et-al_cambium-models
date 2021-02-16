.SUFFIXES : .rst .html .pdf

.rst.pdf :
	rst2pdf -s stylesheet.json $< -o $@

.rst.html :
	rst2html.py $< $@

all: v1.pdf v1.html

v1.pdf : v1.rst

v1.html : v1.rst

clean:
	/bin/rm -f v1.pdf v1.html

#finis