#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"
// bytecode farmat, each instruction has a one-byte operation code, a.k.a opcode

typedef enum
{
    OP_CONSTANT,
    OP_RETURN, // return from the current function
} OpCode;

typedef struct
{
    int count;
    int capacity;
    uint8_t *code;
    ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk);
void freeChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte);
int addConstant(Chunk *chunk, Value value);

#endif