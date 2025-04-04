TEX_DIR := Assets/Tex
PDF_DIR := Assets/Pdf

# Detectar archivo .tex en la raíz automáticamente (asumiendo que solo hay uno)
ROOT_TEX := $(wildcard *.tex)
ROOT_PDF := $(ROOT_TEX:.tex=.pdf)

# Archivos .tex en Assets/Tex
TEX_FILES := $(wildcard $(TEX_DIR)/*.tex)

# Mapear los .tex a sus .pdf esperados
PDF_TARGETS := $(patsubst $(TEX_DIR)/%.tex,$(PDF_DIR)/%.pdf,$(TEX_FILES))

# Regla por defecto: compilar todo
all: $(PDF_TARGETS) $(ROOT_PDF)

# Compilar .tex -> .pdf desde Assets/Tex hacia Assets/Pdf
$(PDF_DIR)/%.pdf: $(TEX_DIR)/%.tex
	@echo "Compilando $< -> $@"
	@latexmk -lualatex -silent -output-directory=$(PDF_DIR) $<
	@latexmk -c -output-directory=$(PDF_DIR)

# Compilar el archivo .tex que esté en la raíz
$(ROOT_PDF): $(ROOT_TEX)
	@echo "Compilando archivo raíz: $<"
	@latexmk -lualatex -silent $<
	@latexmk -c

# Limpiar archivos auxiliares
clean:
	@echo "Limpiando archivos auxiliares..."
	@latexmk -C -output-directory=$(PDF_DIR)
	@latexmk -C

.PHONY: all clean

