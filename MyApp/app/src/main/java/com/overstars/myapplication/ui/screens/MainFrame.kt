package com.overstars.myapplication.ui.screens

import android.annotation.SuppressLint
import androidx.compose.material.*
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.DateRange
import androidx.compose.material.icons.filled.Home
import androidx.compose.material.icons.filled.Person
import androidx.compose.runtime.*
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.tooling.preview.Preview
import com.overstars.myapplication.model.entity.NavigationItem

@SuppressLint("UnusedMaterialScaffoldPaddingParameter")
@Composable
fun MainFrame() {

    val navigationItems = listOf(
        NavigationItem(
            title = "学习",
            icon = Icons.Filled.Home
        ),
        NavigationItem(
            title = "任务",
            icon = Icons.Filled.DateRange
        ),
        NavigationItem(
            title = "我的",
            icon = Icons.Filled.Person
        ),
    )

    var currentNavigationIndex by remember {
        mutableStateOf(0)
    }

    Scaffold (bottomBar = {
        BottomNavigation (
            backgroundColor = MaterialTheme.colors.surface,
        ) {
            navigationItems.forEachIndexed{
                index, navigationItem ->
                BottomNavigationItem(
                    selected = index == currentNavigationIndex,
                    onClick = {
                       currentNavigationIndex = index
                    },
                    icon = {
                       Icon(
                           imageVector = navigationItem.icon,
                           contentDescription = null
                       )
                    },
                    label = {
                       Text(text = navigationItem.title)
                    },
                    selectedContentColor = Color(0xFF149EE7),
                    unselectedContentColor = Color(0xFF979797)
                )
            }
        }
    }) {
        Text(text = "current navigation item $currentNavigationIndex!")
    }
}

@Preview
@Composable
fun MainFramePreview() {
    MainFrame()
}