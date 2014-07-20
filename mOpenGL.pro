
#-------------------------------------------------
#
# Project created by QtCreator 2013-08-26T21:48:26
#
#-------------------------------------------------
CONFIG+=console

QT       += core gui

#INCLUDEPATH+=./glew/include
INCLUDEPATH+=./References/glm
INCLUDEPATH+=./
INCLUDEPATH+=./shapes


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myOPenGL
TEMPLATE = app


QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
    shapes/Rectangle3D.cpp \
    shapes/ShapesMngr.cpp \
    shapes/AdapterFloat3.cpp \
    shapes/Triangle.cpp \
    shapes/Vector4.cpp \
    shaders/ColorShader.cpp \
    EngineGL.cpp \
    MainWindow.cpp \
    WindowGL.cpp \
    debug/moc_mainwindow.cpp \
    debug/moc_windowgl.cpp \
    References/glm/glm/core/dummy.cpp \
    References/glm/test/core/core_func_common.cpp \
    References/glm/test/core/core_func_exponential.cpp \
    References/glm/test/core/core_func_geometric.cpp \
    References/glm/test/core/core_func_integer.cpp \
    References/glm/test/core/core_func_matrix.cpp \
    References/glm/test/core/core_func_noise.cpp \
    References/glm/test/core/core_func_packing.cpp \
    References/glm/test/core/core_func_swizzle.cpp \
    References/glm/test/core/core_func_trigonometric.cpp \
    References/glm/test/core/core_func_vector_relational.cpp \
    References/glm/test/core/core_setup_message.cpp \
    References/glm/test/core/core_setup_precision.cpp \
    References/glm/test/core/core_type_float.cpp \
    References/glm/test/core/core_type_half.cpp \
    References/glm/test/core/core_type_int.cpp \
    References/glm/test/core/core_type_length.cpp \
    References/glm/test/core/core_type_mat2x2.cpp \
    References/glm/test/core/core_type_mat2x3.cpp \
    References/glm/test/core/core_type_mat2x4.cpp \
    References/glm/test/core/core_type_mat3x2.cpp \
    References/glm/test/core/core_type_mat3x3.cpp \
    References/glm/test/core/core_type_mat3x4.cpp \
    References/glm/test/core/core_type_mat4x2.cpp \
    References/glm/test/core/core_type_mat4x3.cpp \
    References/glm/test/core/core_type_mat4x4.cpp \
    References/glm/test/core/core_type_vec1.cpp \
    References/glm/test/core/core_type_vec2.cpp \
    References/glm/test/core/core_type_vec3.cpp \
    References/glm/test/core/core_type_vec4.cpp \
    References/glm/test/external/gli/core/dummy.cpp \
    References/glm/test/gtc/gtc_constants.cpp \
    References/glm/test/gtc/gtc_epsilon.cpp \
    References/glm/test/gtc/gtc_half_float.cpp \
    References/glm/test/gtc/gtc_matrix_access.cpp \
    References/glm/test/gtc/gtc_matrix_integer.cpp \
    References/glm/test/gtc/gtc_matrix_inverse.cpp \
    References/glm/test/gtc/gtc_matrix_transform.cpp \
    References/glm/test/gtc/gtc_noise.cpp \
    References/glm/test/gtc/gtc_quaternion.cpp \
    References/glm/test/gtc/gtc_random.cpp \
    References/glm/test/gtc/gtc_reciprocal.cpp \
    References/glm/test/gtc/gtc_swizzle.cpp \
    References/glm/test/gtc/gtc_type_precision.cpp \
    References/glm/test/gtc/gtc_type_ptr.cpp \
    References/glm/test/gtc/gtc_ulp.cpp \
    References/glm/test/gtx/gtx_bit.cpp \
    References/glm/test/gtx/gtx_gradient_paint.cpp \
    References/glm/test/gtx/gtx_integer.cpp \
    References/glm/test/gtx/gtx_matrix_interpolation.cpp \
    References/glm/test/gtx/gtx_matrix_query.cpp \
    References/glm/test/gtx/gtx_multiple.cpp \
    References/glm/test/gtx/gtx_quaternion.cpp \
    References/glm/test/gtx/gtx_random.cpp \
    References/glm/test/gtx/gtx_rotate_vector.cpp \
    References/glm/test/gtx/gtx_simd_mat4.cpp \
    References/glm/test/gtx/gtx_simd_vec4.cpp \
    References/glm/test/gtx/gtx_string_cast.cpp \
    References/glm/test/gtx/gtx_vector_angle.cpp \
    References/glm/test/gtx/gtx_vector_query.cpp \
    shaders/ArrayColorMap.cpp \
    Shader.cpp \
    VectorFunction4x4.cpp \
    utilities/RefArray.cpp \
    utilities/Iarray.cpp \
    shapes/ITopology.cpp \
    utilities/EngineException.cpp \
    shapes/shape.cpp \
    shapes/IMaterial.cpp \
    shapes/ShapeComposed.cpp \
    utilities/IObservable.cpp

HEADERS  += \
    shapes/Rectangle3D.h \
    shapes/BufferSelect.h \
    globals.h \
    shapes/Vector4.h \
    shapes/Vector3.h \
    shapes/Triangle.h \
    shapes/ShapeBindInfo.h \
    shapes/SubVector.h \
    shapes/ShapesMngr.h \
    shaders/ColorShader.h \
    EngineGL.h \
    WindowGL.h \
    MainWindow.h \
    shapes/Vector3.h \
    References/glew/include/GL/glew.h \
    References/glew/include/GL/glxew.h \
    References/glew/include/GL/wglew.h \
    References/glm/glm/core/_detail.hpp \
    References/glm/glm/core/_fixes.hpp \
    References/glm/glm/core/_swizzle.hpp \
    References/glm/glm/core/_swizzle_func.hpp \
    References/glm/glm/core/_vectorize.hpp \
    References/glm/glm/core/func_common.hpp \
    References/glm/glm/core/func_exponential.hpp \
    References/glm/glm/core/func_geometric.hpp \
    References/glm/glm/core/func_integer.hpp \
    References/glm/glm/core/func_matrix.hpp \
    References/glm/glm/core/func_noise.hpp \
    References/glm/glm/core/func_packing.hpp \
    References/glm/glm/core/func_trigonometric.hpp \
    References/glm/glm/core/func_vector_relational.hpp \
    References/glm/glm/core/hint.hpp \
    References/glm/glm/core/intrinsic_common.hpp \
    References/glm/glm/core/intrinsic_exponential.hpp \
    References/glm/glm/core/intrinsic_geometric.hpp \
    References/glm/glm/core/intrinsic_matrix.hpp \
    References/glm/glm/core/intrinsic_trigonometric.hpp \
    References/glm/glm/core/intrinsic_vector_relational.hpp \
    References/glm/glm/core/setup.hpp \
    References/glm/glm/core/type.hpp \
    References/glm/glm/core/type_float.hpp \
    References/glm/glm/core/type_gentype.hpp \
    References/glm/glm/core/type_half.hpp \
    References/glm/glm/core/type_int.hpp \
    References/glm/glm/core/type_mat.hpp \
    References/glm/glm/core/type_mat2x2.hpp \
    References/glm/glm/core/type_mat2x3.hpp \
    References/glm/glm/core/type_mat2x4.hpp \
    References/glm/glm/core/type_mat3x2.hpp \
    References/glm/glm/core/type_mat3x3.hpp \
    References/glm/glm/core/type_mat3x4.hpp \
    References/glm/glm/core/type_mat4x2.hpp \
    References/glm/glm/core/type_mat4x3.hpp \
    References/glm/glm/core/type_mat4x4.hpp \
    References/glm/glm/core/type_size.hpp \
    References/glm/glm/core/type_vec.hpp \
    References/glm/glm/core/type_vec1.hpp \
    References/glm/glm/core/type_vec2.hpp \
    References/glm/glm/core/type_vec3.hpp \
    References/glm/glm/core/type_vec4.hpp \
    References/glm/glm/gtc/constants.hpp \
    References/glm/glm/gtc/epsilon.hpp \
    References/glm/glm/gtc/half_float.hpp \
    References/glm/glm/gtc/matrix_access.hpp \
    References/glm/glm/gtc/matrix_integer.hpp \
    References/glm/glm/gtc/matrix_inverse.hpp \
    References/glm/glm/gtc/matrix_transform.hpp \
    References/glm/glm/gtc/noise.hpp \
    References/glm/glm/gtc/quaternion.hpp \
    References/glm/glm/gtc/random.hpp \
    References/glm/glm/gtc/reciprocal.hpp \
    References/glm/glm/gtc/swizzle.hpp \
    References/glm/glm/gtc/type_precision.hpp \
    References/glm/glm/gtc/type_ptr.hpp \
    References/glm/glm/gtc/ulp.hpp \
    References/glm/glm/gtx/associated_min_max.hpp \
    References/glm/glm/gtx/bit.hpp \
    References/glm/glm/gtx/closest_point.hpp \
    References/glm/glm/gtx/color_cast.hpp \
    References/glm/glm/gtx/color_space.hpp \
    References/glm/glm/gtx/color_space_YCoCg.hpp \
    References/glm/glm/gtx/compatibility.hpp \
    References/glm/glm/gtx/component_wise.hpp \
    References/glm/glm/gtx/constants.hpp \
    References/glm/glm/gtx/epsilon.hpp \
    References/glm/glm/gtx/euler_angles.hpp \
    References/glm/glm/gtx/extend.hpp \
    References/glm/glm/gtx/extented_min_max.hpp \
    References/glm/glm/gtx/fast_exponential.hpp \
    References/glm/glm/gtx/fast_square_root.hpp \
    References/glm/glm/gtx/fast_trigonometry.hpp \
    References/glm/glm/gtx/gradient_paint.hpp \
    References/glm/glm/gtx/handed_coordinate_space.hpp \
    References/glm/glm/gtx/inertia.hpp \
    References/glm/glm/gtx/int_10_10_10_2.hpp \
    References/glm/glm/gtx/integer.hpp \
    References/glm/glm/gtx/intersect.hpp \
    References/glm/glm/gtx/log_base.hpp \
    References/glm/glm/gtx/matrix_cross_product.hpp \
    References/glm/glm/gtx/matrix_interpolation.hpp \
    References/glm/glm/gtx/matrix_major_storage.hpp \
    References/glm/glm/gtx/matrix_operation.hpp \
    References/glm/glm/gtx/matrix_query.hpp \
    References/glm/glm/gtx/mixed_product.hpp \
    References/glm/glm/gtx/multiple.hpp \
    References/glm/glm/gtx/noise.hpp \
    References/glm/glm/gtx/norm.hpp \
    References/glm/glm/gtx/normal.hpp \
    References/glm/glm/gtx/normalize_dot.hpp \
    References/glm/glm/gtx/number_precision.hpp \
    References/glm/glm/gtx/ocl_type.hpp \
    References/glm/glm/gtx/optimum_pow.hpp \
    References/glm/glm/gtx/orthonormalize.hpp \
    References/glm/glm/gtx/perpendicular.hpp \
    References/glm/glm/gtx/polar_coordinates.hpp \
    References/glm/glm/gtx/projection.hpp \
    References/glm/glm/gtx/quaternion.hpp \
    References/glm/glm/gtx/random.hpp \
    References/glm/glm/gtx/raw_data.hpp \
    References/glm/glm/gtx/reciprocal.hpp \
    References/glm/glm/gtx/rotate_vector.hpp \
    References/glm/glm/gtx/simd_mat4.hpp \
    References/glm/glm/gtx/simd_vec4.hpp \
    References/glm/glm/gtx/spline.hpp \
    References/glm/glm/gtx/std_based_type.hpp \
    References/glm/glm/gtx/string_cast.hpp \
    References/glm/glm/gtx/transform.hpp \
    References/glm/glm/gtx/transform2.hpp \
    References/glm/glm/gtx/ulp.hpp \
    References/glm/glm/gtx/unsigned_int.hpp \
    References/glm/glm/gtx/vec1.hpp \
    References/glm/glm/gtx/vector_access.hpp \
    References/glm/glm/gtx/vector_angle.hpp \
    References/glm/glm/gtx/vector_query.hpp \
    References/glm/glm/gtx/verbose_operator.hpp \
    References/glm/glm/gtx/wrap.hpp \
    References/glm/glm/virtrev/xstream.hpp \
    References/glm/glm/ext.hpp \
    References/glm/glm/glm.hpp \
    References/glm/test/external/gli/core/generate_mipmaps.hpp \
    References/glm/test/external/gli/core/image2d.hpp \
    References/glm/test/external/gli/core/operation.hpp \
    References/glm/test/external/gli/core/operator.hpp \
    References/glm/test/external/gli/core/shared_array.hpp \
    References/glm/test/external/gli/core/shared_ptr.hpp \
    References/glm/test/external/gli/core/size.hpp \
    References/glm/test/external/gli/core/texture2d.hpp \
    References/glm/test/external/gli/core/texture2d_array.hpp \
    References/glm/test/external/gli/core/texture_cube.hpp \
    References/glm/test/external/gli/core/texture_cube_array.hpp \
    References/glm/test/external/gli/gtx/compression.hpp \
    References/glm/test/external/gli/gtx/fetch.hpp \
    References/glm/test/external/gli/gtx/gl_texture2d.hpp \
    References/glm/test/external/gli/gtx/gradient.hpp \
    References/glm/test/external/gli/gtx/loader.hpp \
    References/glm/test/external/gli/gtx/loader_dds10.hpp \
    References/glm/test/external/gli/gtx/loader_dds9.hpp \
    References/glm/test/external/gli/gtx/loader_tga.hpp \
    References/glm/test/external/gli/gtx/wavelet.hpp \
    References/glm/test/external/gli/gli.hpp \
    ArrayColorMap.h \
    Camera.h \
    ICamera.h \
    opointer.h \
    ui_mainwindow.h \
    VectorFunction4x4.h \
    utilities/RefArray.h \
    shapes/ITopology.h \
    utilities/EngineException.h \
    shapes/IShape.h \
    shapes/Shape.h \
    utilities/IArray.h \
    shapes/IMaterial.h \
    shapes/ShapeComposed.h \
    utilities/IObservable.h

FORMS    += mainwindow.ui

INCLUDEPATH+=./
