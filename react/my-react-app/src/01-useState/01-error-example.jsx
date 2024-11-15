import { useState } from 'react'

const ErrorExample = () => {
  const [count, setCount] = useState(0)

  const handleClick = () => {
    setCount(count + 1)
  }

  return (
    <div>
      <h2>You clicked the button {count} times</h2>
      <button type="button" onClick={handleClick}>
        Click Me
      </button>
    </div>
  )
}

export default ErrorExample
