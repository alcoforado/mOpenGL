
OBJS=$(wildcard *.glsl)
SRC=$(pathsubst %.glsl,%.h,$(OBJS))
BuildGLSL: $(patsubst %.glsl,%.h,$(wildcard *.glsl))  
	
%.h : %.glsl 
	../../tools/TextToHeader/TextToHeader $<

clean: 
	rm *.h
