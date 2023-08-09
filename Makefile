.PHONY : sequence,sequences,runner,runner_
.PHONY : pb,pbRunner,pbSequence,pbSequences


all:
	make sequence
	make runner
	make sequences
	make runner_


pb:
	make pbSequence
	make pbRunner
	make pbSequences

pbRunner:
	mkdir -p build
	cd build && cmake -S .. -B . -G "Unix Makefiles"

pbSequence:
	mkdir -p setup/build
	cd setup/build && cmake -S .. -B . -G "Unix Makefiles"

pbSequences:
	mkdir -p creator/build
	cd creator/build && cmake -S .. -B . -G "Unix Makefiles"


sequence:
	mkdir -p output
	cd setup/build && make

sequences:
	mkdir -p output/sequences
	cd creator/build && make

runner:
	mkdir -p output/sequences
	cd build && make

runner_:
	cd output && runner

