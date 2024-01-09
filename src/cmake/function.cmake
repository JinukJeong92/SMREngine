
function(find_files replace)
    set(file_List)

    foreach(CUR_DIR ${GDIRECTORY})
    	file(GLOB CUR_DIR_SOURCES
        	"${CUR_DIR}/*.cpp"
        	"${CUR_DIR}/*.h"
    	)

	if(${replace})
		string(REPLACE ${replace} "" modified_string ${CUR_DIR})
    		source_group(${modified_string} FILES ${CUR_DIR_SOURCES})
	else()
    		source_group(${CUR_DIR} FILES ${CUR_DIR_SOURCES})
	endif()
	list(APPEND file_List ${CUR_DIR_SOURCES})
    endforeach()
    set(GFILES ${GFILES} ${file_List} PARENT_SCOPE)
endfunction()


function(find_subdirectories RELATE STARTDIR)
    file(GLOB_RECURSE SUBDIRECTORIES LIST_DIRECTORIES true RELATIVE ${RELATE} ${RELATE}/${STARTDIR}/*)
    set(dir_List ${STARTDIR})

    foreach(SUBDIR ${SUBDIRECTORIES})
        if(IS_DIRECTORY ${CURRENT_DIR}/${SUBDIR})
            list(APPEND dir_List ${SUBDIR})
        endif()
    endforeach()

    set(GDIRECTORY ${GDIRECTORY} ${dir_List} PARENT_SCOPE)
endfunction()

function(include_subdirectories_depth1 RELATE STARTDIR)
    file(GLOB SUBDIRECTORIES LIST_DIRECTORIES true RELATIVE ${RELATE} ${RELATE}/${STARTDIR}/*)
    set(dir_List ${STARTDIR})

    foreach(SUBDIR ${SUBDIRECTORIES})
        if(IS_DIRECTORY ${CURRENT_DIR}/${SUBDIR})
            list(APPEND dir_List ${SUBDIR})
        endif()
    endforeach()
    include_directories(${dir_List})
endfunction()
