package com.example.androidcompose.layout

import android.annotation.SuppressLint
import androidx.compose.animation.core.Animatable
import androidx.compose.animation.core.TweenSpec
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.shape.CircleShape
import androidx.compose.foundation.shape.CutCornerShape
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material.*
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import kotlinx.coroutines.coroutineScope
import kotlinx.coroutines.launch
import kotlin.math.abs
import kotlin.math.roundToInt

@SuppressLint("UnusedMaterialScaffoldPaddingParameter")
@Composable
fun ScaffoldSample() {
    val navs = listOf("Home", "Profile", "Settings")
    var currentNavIndex by remember{
        mutableStateOf(0)
    }

    val scaffoldState = rememberScaffoldState()
    val coroutineScope = rememberCoroutineScope()

    Scaffold (
        scaffoldState = scaffoldState,
        topBar = {
            TopAppBar(title = {
                Text(text = "Title")
            }, navigationIcon = {
                IconButton(onClick = {
                    coroutineScope.launch {
                        scaffoldState.drawerState.open()
                    }
                }) {
                    Icon(
                        imageVector = Icons.Default.Build,
                        contentDescription = null
                    )
                }
            }, actions = {
                IconButton(onClick = {
                        coroutineScope.launch {
                            scaffoldState.snackbarHostState.showSnackbar(
                                message = "已经添加成功了",
                                actionLabel = "Undo"
                            )
                        }
                    }
                ) {
                    Icon(
                        imageVector = Icons.Default.Add,
                        contentDescription = null
                    )
                }
                Spacer(modifier = Modifier.width(8.dp))
                Text(text = "Edit")
            })
        }, bottomBar = {
            BottomNavigation() {
                navs.forEachIndexed { index, s ->
                    BottomNavigationItem(
                        selected = currentNavIndex == index,
                        onClick = {
                            currentNavIndex = index
                        },
                        icon = {
    //                        BadgeBox(badgeContent = {
    //                            Text(text = "99+")
    //                        }) {
                                Icon(
                                    Icons.Default.AccountBox,
                                    contentDescription = null
                                )
    //                        }
                        },
                        label = {
                            Text(s)
                        }
                    )
                }
            }
        }, drawerContent = {
            Text(text = "Drawer Content")
        },
        drawerBackgroundColor = Color.Yellow,
        drawerContentColor = Color.Red,
        drawerScrimColor = Color.Green
        ) {
            Text(text = "Scaffold Body Content. ${navs[currentNavIndex]}")
        }
}


@OptIn(ExperimentalMaterialApi::class)
@SuppressLint("UnusedMaterialScaffoldPaddingParameter")
@Composable
fun ScaffoldSample3() {
    val navs = listOf("Home", "Profile", "Settings")
    var currentNavIndex by remember{
        mutableStateOf(0)
    }

    val scaffoldState = rememberBackdropScaffoldState(BackdropValue.Concealed)
    val coroutineScope = rememberCoroutineScope()

    BackdropScaffold (
        scaffoldState = scaffoldState,
        appBar = {
            TopAppBar(title = {
                Text(text = "Title")
            }, navigationIcon = {
                IconButton(onClick = {
                    if (scaffoldState.isConcealed) {
                        coroutineScope.launch {
                            scaffoldState.reveal()
                        }
                    } else {
                        coroutineScope.launch {
                            scaffoldState.conceal()
                        }
                    }

                }) {
                    if (scaffoldState.isConcealed) {
                        Icon(
                            imageVector = Icons.Default.Menu,
                            contentDescription = null
                        )
                    } else {
                        Icon(
                            imageVector = Icons.Default.Close,
                            contentDescription = null
                        )
                    }

                }
            }, actions = {
                IconButton(onClick = {
                    coroutineScope.launch {
                        scaffoldState.snackbarHostState.showSnackbar(
                            message = "已经添加成功了",
                            actionLabel = "Undo"
                        )
                    }
                }
                ) {
                    Icon(
                        imageVector = Icons.Default.Add,
                        contentDescription = null
                    )
                }
                Spacer(modifier = Modifier.width(8.dp))
                Text(text = "Edit")
            })
        },
        frontLayerContent = {
            Text(text = "Scaffold Body Content. ${navs[currentNavIndex]}")
        },
        backLayerContent = {
            LazyColumn {
                items(10) {
                    ListItem (
                        text = {
                            Text(text = "List Item $it")
                        }
                    )
                }
            }
            Text(text = "BackLayer Content")
        }
    )
}


@Preview
@Composable
fun ScaffoldSamplePreview() {
    ScaffoldSample3()
}