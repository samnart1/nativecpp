import { useState } from 'react'

const UseObject = () => {
  const [person, setPerson] = useState({
    name: 'Frafra',
    age: 82,
    hobby: 'enjoys screaming at the computer',
  })

  const showPerson = () => {
    setPerson({ ...person, name: 'isaac', age: 97 })
  }

  const { name, age, hobby } = person

  return (
    <>
      <h2>{name}</h2>
      <h2>{age}</h2>
      <h4>Hobby: {hobby}</h4>
      <button type="button" onClick={showPerson}>
        show isaac
      </button>
    </>
  )
}

export default UseObject
