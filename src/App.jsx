import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import { File.jsx } from './components/File.jsx';

function App() {
  const [count, setCount] = useState(0)

  return (
    <>
      <h1>Hello World !</h1>
      <File name="Test" image="Test" />
    </>
  )
}

export default App
