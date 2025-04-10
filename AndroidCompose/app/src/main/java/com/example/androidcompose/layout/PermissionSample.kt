package com.example.androidcompose.layout

import android.Manifest
import android.annotation.SuppressLint
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material.Button
import androidx.compose.material.Scaffold
import androidx.compose.material.Text
import androidx.compose.material.TopAppBar
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import com.google.accompanist.permissions.*

@SuppressLint("UnusedMaterialScaffoldPaddingParameter")
@OptIn(ExperimentalPermissionsApi::class)
@Composable
fun PermissionSample() {

    val permissionState = rememberPermissionState(
        permission = Manifest.permission.CAMERA
    )

    Scaffold (
        topBar = {
            TopAppBar (
                title = { Text(text = "Permission Sample") }
            )
        }
    ) {
        Column (
            Modifier.fillMaxSize(),
            verticalArrangement = Arrangement.Center,
            horizontalAlignment = Alignment.CenterHorizontally
        ) {
            when(permissionState.status) {
                PermissionStatus.Granted -> {
                    Text(text = "Permission Granted")
                }

                is PermissionStatus.Denied -> {

                    Column {
                        val text = if ((permissionState.status as PermissionStatus.Denied).shouldShowRationale) {
                            "相机权限已拒绝，点击按钮再次请求"
                        } else {
                            "Permission Denied"
                        }
                        Text(text = text)
                        Button(onClick = {
                            permissionState.launchPermissionRequest() }
                        ) {
                            Text(text = "Request Permission")
                        }
                    }
                }
            }
        }
    }
}


@SuppressLint("UnusedMaterialScaffoldPaddingParameter")
@OptIn(ExperimentalPermissionsApi::class)
@Composable
fun PermissionSample2() {

    val permissionState = rememberMultiplePermissionsState(
        listOf(Manifest.permission.CAMERA, Manifest.permission.RECORD_AUDIO)
    )

    Scaffold (
        topBar = {
            TopAppBar (
                title = { Text(text = "Permission Sample") }
            )
        }
    ) {
        Column (
            Modifier.fillMaxSize(),
            verticalArrangement = Arrangement.Center,
            horizontalAlignment = Alignment.CenterHorizontally
        ) {
            permissionState.permissions.forEach {
                permissionState -> when(permissionState.permission) {
                    Manifest.permission.CAMERA -> {
                        when(permissionState.status) {
                            PermissionStatus.Granted -> {
                                Text(text = "CAMERA Permission Granted")
                            }

                            is PermissionStatus.Denied -> {

                                Column {
                                    val text = if ((permissionState.status as PermissionStatus.Denied).shouldShowRationale) {
                                        "相机权限已拒绝，点击按钮再次请求"
                                    } else {
                                        "CAMERA Permission Denied"
                                    }
                                    Text(text = text)
                                    Button(onClick = {
                                        permissionState.launchPermissionRequest() }
                                    ) {
                                        Text(text = "CAMERA Request Permission")
                                    }
                                }
                            }
                        }
                    }

                    Manifest.permission.RECORD_AUDIO -> {
                        when(permissionState.status) {
                            PermissionStatus.Granted -> {
                                Text(text = "RECORD_AUDIO Permission Granted")
                            }

                            is PermissionStatus.Denied -> {

                                Column {
                                    val text = if ((permissionState.status as PermissionStatus.Denied).shouldShowRationale) {
                                        "录音权限已拒绝，点击按钮再次请求"
                                    } else {
                                        "RECORD_AUDIO Permission Denied"
                                    }
                                    Text(text = text)
                                    Button(onClick = {
                                        permissionState.launchPermissionRequest() }
                                    ) {
                                        Text(text = "RECORD_AUDIO Request Permission")
                                    }
                                }
                            }
                        }
                    }
                }
            }

            Button(onClick = {
                permissionState.launchMultiplePermissionRequest()
            }) {
                Text(text = "Request Permission")
            }
        }
    }
}

@Preview
@Composable
fun PermissionSamplePreview() {
    PermissionSample2()
}