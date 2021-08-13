#ifndef _SNAPPY_DECOMPRESSION_H_
#define _SNAPPY_DECOMPRESSION_H_

#include "snappy_cuda.h"

/**
 * Prepares the necessary constructs for running decompression.
 * Allocates the output buffer to match the size of the decompressed file.
 *
 * @param input: holds input buffer information
 * @param output: holds output buffer information
 * @param runtime: struct holding breakdown of runtimes for different parts of the program
 * @return SNAPPY_OK if successful, error code otherwise
 */
snappy_status setup_decompression(struct host_buffer_context *input, struct host_buffer_context *output, struct program_runtime *runtime);

/**
 * Prepares the necessary constructs for running decompression on the GPU.
 * Allocates the output buffer to match the size of the decompressed file.
 *
 * @param input: holds input buffer information
 * @param output: holds output buffer information
 * @param runtime: struct holding breakdown of runtimes for different parts of the program
 * @return SNAPPY_OK if successful, error code otherwise
 */
snappy_status setup_decompression_cuda(struct host_buffer_context *input, struct host_buffer_context *output, struct program_runtime *runtime);

/**
 * Releases memory buffers allocated for decompression on the host and device.
 * 
 * @param input: holds input buffer information
 * @param output: holds output buffer information
 * @param runtime: struct holding break down of runtimes for different parts of the program
 */
void terminate_decompression(struct host_buffer_context *input, struct host_buffer_context *output, struct program_runtime *runtime);

/**
 * Perform the Snappy decompression on the host.
 *
 * @param input: holds input buffer information
 * @param output: holds output buffer information
 * @return SNAPPY_OK if successful, error code otherwise
 */
snappy_status snappy_decompress_host(struct host_buffer_context *input, struct host_buffer_context *output);

/**
 * Perform the Snappy decompression on the GPU.
 *
 * @param input: holds input buffer information
 * @param output: holds output buffer information
 * @param runtime: struct holding breakdown of runtimes for different parts of the program
 * @return SNAPPY_OK if successful, error code otherwise
 */
snappy_status snappy_decompress_cuda(struct host_buffer_context *input, struct host_buffer_context *output, struct program_runtime *runtime);

#endif /* _SNAPPY_DECOMPRESSION_H_ */
