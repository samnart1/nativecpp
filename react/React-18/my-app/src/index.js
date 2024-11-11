import React from 'react'
import ReactDOM from 'react-dom/client'

function Greeting() {
  return (
    <>
      <h2>Hello world</h2>
      <ul>
        <li>
          <a href="#">hello world</a>
        </li>
      </ul>
    </>
  )
}

const root = ReactDOM.createRoot(document.getElementById('root'))

root.render(<Greeting />)
