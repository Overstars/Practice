package com.example.androidcompose.layout

import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.runtime.Composable
import androidx.compose.material.*
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.tooling.preview.Preview
import androidx.navigation.NavController
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController

@Composable
fun NavSample() {

    val navController = rememberNavController()

    NavHost(
        navController = navController,
        startDestination = "first" // 设置起始页
    ) {
        // 和startDestination一样，顺序随意
        composable(route = "first") {
            FirstScreen() {
                navController.navigate("second")
            }
        }

        composable(route = "second") {
            SecondScreen(navController)
        }

        composable(route = "third") {
            ThirdScreen() {
                navController.popBackStack(
                    "first", // 返回到指定页面
                    inclusive = false // 是否包含指定页面
                )
            }
        }
    }

}

@Composable
fun FirstScreen(onNavigatorToSecond:() -> Unit) {
    Column (
        modifier = Modifier
            .fillMaxSize()
            .background(Color.Red),
    ) {
        Text(
            text = "First Screen"
        )
        Button(onClick = {
            onNavigatorToSecond()
//            navController.navigate("second")
        }) {
            Text(text = "Go to second screen")
        }
    }
}

@Composable
fun SecondScreen(navController: NavController) {
    Column (
        modifier = Modifier
            .fillMaxSize()
            .background(Color.Blue),
    ) {
        Text(
            text = "Second Screen"
        )
        Button(onClick = {
            navController.navigate("third")
        }) {
            Text(text = "Go to Third screen")
        }
    }
}

@Composable
fun ThirdScreen(onNavigatorToRoot: () -> Unit) {
    Column (
        modifier = Modifier
            .fillMaxSize()
            .background(Color.Yellow),
    ) {
        Text(
            text = "Third Screen"
        )
        Button(onClick = {
//            navController.navigate("first")
            onNavigatorToRoot()
        }) {
            Text(text = "Go to First screen")
        }
    }
}

@Preview
@Composable
fun NavSamplePreview() {
    NavSample()
}