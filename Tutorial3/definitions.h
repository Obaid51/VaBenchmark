#pragma once
#define CL_USE_DEPRECATED_OPENCL_1_2_APIS
#include <CL/cl.hpp>
#include <cassert>
#include <fstream>

#define EXPORT_VAR extern
#define EXPORT_FUNC

typedef float scalar;

#define DT 0.100000f
#define NSIZE 7
#define DEVICE_INDEX 2

extern "C" {
	EXPORT_VAR scalar* aSpikes;
	EXPORT_VAR scalar* xSpikes;
	EXPORT_VAR scalar* ySpikes;
	EXPORT_VAR scalar* zSpikes;
	EXPORT_VAR scalar* aSynapses;
	EXPORT_VAR scalar* xSpikes;
	EXPORT_VAR scalar* ySpikes;
	EXPORT_VAR scalar* zSpikes;
	EXPORT_VAR unsigned int* glbSpkCntNeurons;
	EXPORT_VAR unsigned int* glbSpkNeurons;
	EXPORT_VAR scalar* VNeurons;
	EXPORT_VAR scalar* UNeurons;
	EXPORT_VAR scalar* aNeurons;
	EXPORT_VAR scalar* bNeurons;
	EXPORT_VAR scalar* cNeurons;
	EXPORT_VAR scalar* dNeurons;
	EXPORT_VAR unsigned long long iT;
	EXPORT_VAR float t;

	EXPORT_FUNC void updateNeurons(float t);
	EXPORT_FUNC void allocateMem();
	EXPORT_FUNC void initialize();
	EXPORT_FUNC void initKernelPrograms();
	EXPORT_FUNC void initKernels();
	EXPORT_FUNC void initBuffers();
	EXPORT_FUNC void initializeOpenCL();
	EXPORT_FUNC void stepTime();
	EXPORT_FUNC scalar* getCurrentVNeurons();
	EXPORT_FUNC void pullCurrentVNeuronsFromDevice();
	EXPORT_FUNC scalar* getCurrentxSynapses();
	EXPORT_FUNC scalar* pullCurrentxSpikes();
	EXPORT_FUNC scalar* pullCurrentSynapsesFromDevice();
	EXPORT_FUNC scalar* pullCurrentSpikesFromDevice();


}


// Declaration of OpenCL functions
namespace opencl {

	void setUpContext(cl::Context& context, cl::Device& device, const int deviceIndex);
	void createProgram(const std::string& filename, cl::Program& program, cl::Context& context);
	std::string getCLError(cl_int errorCode);

}