/*!
 * File:
 *   MetaTypes (.h and .cpp)
 *
 * Description:
 *    This file provides the definition of the enumerated types used by
 *    metaObjects as well as the record structured used to describe the
 *    fields to be read and written by MetaObjects.
 *
 *
 * \author Stephen R. Aylward
 * \date August 29, 1999
 * 
 */


#ifndef METATYPES_H
#define METATYPES_H

// Value types for the variables in a metaFile
// Format for variables defined in a metaFile is
//    <variable> = <value>
//       where <variable> is a designated fieldname/keyword (e.g., NDims)
//          and value is an instance of that fieldname's associated valueType
#define MET_NUM_VALUE_TYPES 25

typedef enum
   {
   MET_NONE,
   MET_ASCII_CHAR, 
   MET_CHAR, 
   MET_UCHAR, 
   MET_SHORT,
   MET_USHORT,
   MET_INT, 
   MET_UINT,
   MET_LONG,
   MET_ULONG,
   MET_FLOAT, 
   MET_DOUBLE,
   MET_STRING, 
   MET_CHAR_ARRAY, 
   MET_UCHAR_ARRAY, 
   MET_SHORT_ARRAY,
   MET_USHORT_ARRAY,
   MET_INT_ARRAY, 
   MET_UINT_ARRAY,
   MET_LONG_ARRAY,
   MET_ULONG_ARRAY,
   MET_FLOAT_ARRAY, 
   MET_DOUBLE_ARRAY,
   MET_FLOAT_MATRIX,
   MET_OTHER
   } MET_ValueEnumType;


const unsigned char MET_ValueTypeSize[MET_NUM_VALUE_TYPES] = {
   0, 1, 1, 1, 2, 2, 4, 4, 4, 4, 4, 8, 1, 1, 1, 2, 2, 4, 4, 4, 4, 4, 8, 4, 0 };

const char MET_ValueTypeName[MET_NUM_VALUE_TYPES][17] = {
   {'M','E','T','_','N','O','N','E','\0',' ',' ',' ',' ',' ',' ',' ',' '},
   {'M','E','T','_','A','S','C','I','I','_','C','H','A','R','\0',' ',' '},
   {'M','E','T','_','C','H','A','R','\0',' ',' ',' ',' ',' ',' ',' ',' '},
   {'M','E','T','_','U','C','H','A','R','\0',' ',' ',' ',' ',' ',' ',' '},
   {'M','E','T','_','S','H','O','R','T','\0',' ',' ',' ',' ',' ',' ',' '},
   {'M','E','T','_','U','S','H','O','R','T','\0',' ',' ',' ',' ',' ',' '},
   {'M','E','T','_','I','N','T','\0',' ',' ',' ',' ',' ',' ',' ',' ',' '},
   {'M','E','T','_','U','I','N','T','\0',' ',' ',' ',' ',' ',' ',' ',' '},
   {'M','E','T','_','L','O','N','G','\0',' ',' ',' ',' ',' ',' ',' ',' '},
   {'M','E','T','_','U','L','O','N','G','\0',' ',' ',' ',' ',' ',' ',' '},
   {'M','E','T','_','F','L','O','A','T','\0',' ',' ',' ',' ',' ',' ',' '},
   {'M','E','T','_','D','O','U','B','L','E','\0',' ',' ',' ',' ',' ',' '},
   {'M','E','T','_','S','T','R','I','N','G','\0',' ',' ',' ',' ',' ',' '},
   {'M','E','T','_','C','H','A','R','_','A','R','R','A','Y','\0',' ',' '},
   {'M','E','T','_','U','C','H','A','R','_','A','R','R','A','Y','\0',' '},
   {'M','E','T','_','S','H','O','R','T','_','A','R','R','A','Y','\0',' '},
   {'M','E','T','_','U','S','H','O','R','T','_','A','R','R','A','Y','\0'},
   {'M','E','T','_','I','N','T','_','A','R','R','A','Y','\0',' ',' ',' '},
   {'M','E','T','_','U','I','N','T','_','A','R','R','A','Y','\0',' ',' '},
   {'M','E','T','_','L','O','N','G','_','A','R','R','A','Y','\0',' ',' '},
   {'M','E','T','_','U','L','O','N','G','_','A','R','R','A','Y','\0',' '},
   {'M','E','T','_','F','L','O','A','T','_','A','R','R','A','Y','\0',' '},
   {'M','E','T','_','D','O','U','B','L','E','_','A','R','R','A','Y','\0'},
   {'M','E','T','_','F','L','O','A','T','_','M','A','T','R','I','X','\0'},
   {'M','E','T','_','O','T','H','E','R','\0',' ',' ',' ',' ',' ',' ',' '}};


typedef enum { MET_ORIENTATION_RL, MET_ORIENTATION_LR, MET_ORIENTATION_AP,
       MET_ORIENTATION_PA, MET_ORIENTATION_SI, MET_ORIENTATION_IS,
       MET_ORIENTATION_UNKNOWN } MET_OrientationEnumType;

#define MET_NUM_ORIENTATION_TYPES 7

const char MET_OrientationTypeName[MET_NUM_ORIENTATION_TYPES][3] = {
   {'R','L','\0'},
   {'L','R','\0'},
   {'A','P','\0'},
   {'P','A','\0'},
   {'S','I','\0'},
   {'I','S','\0'},
   {'?','?','\0'}};

   
// Structure used to define a field (variable = value definition) in a MetaFile
typedef struct
   {
   char           name[255];  // Fieldname / keyword to designate a variable
   MET_ValueEnumType  type;   // Expected value type of the field
   bool           required;   // Is this field a required field in a metaFile
   int            dependsOn;  // If value type is an array, the size of this 
                              //    array can be defined by a different field
                              //    (e.g., DimSize array depends on NDims)
   bool           defined;    // Has this field already been defined in the
                              //    MetaFile being parsed
   int            length;     // Actual/expect length of an array
   double         value[255]; // Memory and pointers for the field's value(s).
   bool           terminateRead;  // Set to true if field indicates end of 
                                  //   meta data
   } MET_FieldRecordType;


#endif
