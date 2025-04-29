## 安装electron
如果package-lock.json正常，执行
```
npm install
```
否则从0初始化项目
```
mkdir my-electron-app && cd my-electron-app
npm init
npm install electron --save-dev
```


## 升级npm和node.js版本
从官网下载LTS版本：https://nodejs.org/en/download/

```
npm install npm@latest -g
```
## 运行
```
npm run start
```

## 打包

### 安装Electron Forge

```
npm install --save-dev @electron-forge/cli
npx electron-forge import
```

### 构建可分发文件
最好在forge.config.js对代码进行签名
```
npm run make
```

# 尝试开发一个NoSQL连接客户端

```
+-----------------------+
| Electron Renderer     |  React UI
+-----------------------+
         ↓ IPC
+-----------------------+
| Electron Main Process |  Node.js 主逻辑
+-----------------------+
         ↓ Native API
+-----------------------+
| C++ Native Addon      |  LevelDB/RocksDB 操作
+-----------------------+
         ↓ TCP
+-----------------------+
| Redis Server          |  远程/本地 Redis 服务
+-----------------------+
```