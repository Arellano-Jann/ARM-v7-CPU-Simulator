main: main.o Converter.o
	g++ -std=c++11 -o $@ $^

clean:
	rm main