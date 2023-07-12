import open3d as o3d
import wget
import numpy as np
import time
# download 3d data
url = 'https://github.com/AarohiSingla/Open3D-Tutorial/blob/main/bunny.pcd'

# bunny_data = wget.download(url)

path = '/home/bhavik/Downloads/kitchen/Rf3.pcd'

obj_path = ''

pcd = o3d.io.read_point_cloud(path)

downsamp_time_init = time.time()

# Downsampling pointcloud
downpcd = pcd.voxel_down_sample(voxel_size=0.05)
# o3d.visualization.draw_geometries([downpcd])

downsamp_time_finish = time.time()

print('Downsampling took ' , (downsamp_time_finish - downsamp_time_init)*1000 , 'ms')

# create mesh from pcd alpha shape

# mesh_time_init = time.time()

# mesh = o3d.geometry.TriangleMesh.create_from_point_cloud_alpha_shape(pcd, 0.1)
# mesh.compute_vertex_normals()

# mesh_time_end = time.time()

# print('Mesh generation from pcd took ' , (mesh_time_end - mesh_time_init)*1000 , 'ms')

# o3d.visualization.draw_geometries([mesh], mesh_show_back_face=True)


# Create mesh using ball povting method
pcd.compute_vertex_normals()

mesh_time_init = time.time()

mesh, densities = o3d.geometry.TriangleMesh.create_from_point_cloud_poisson(pcd, depth=9)

# radii = [0.005, 0.01, 0.02, 0.04]
# rec_mesh = o3d.geometry.TriangleMesh.create_from_point_cloud_ball_pivoting( pcd, o3d.utility.DoubleVector(radii))

mesh_time_end = time.time()

print('Mesh generation from pcd took ' , (mesh_time_end - mesh_time_init)*1000 , 'ms')

o3d.visualization.draw_geometries([pcd, mesh])


#### NOTE: 
#  Downsampled point cloud generates mesh faster about 20-30 times than original 


# # Create mesh using ball povting method

# radii = [0.005, 0.01, 0.02, 0.04]

